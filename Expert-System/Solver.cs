using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ExpertSystem.Models;

namespace ExpertSystem
{
    public class Solver
    {
        private readonly Parser _parser;

        public Dictionary<string, Fact> AllAvailableFacts { get; set; }
        private List<Rule> RulesList { get; set; }
        private List<string> _queryFactsList;

        public Solver(Parser parser)
        {
            _parser = parser;
        }

        public void Init()
        {
            AllAvailableFacts = _parser.GetAllFacts();
            _queryFactsList = _parser.GetQueryFacts(AllAvailableFacts);
            _parser.InitiateFacts(AllAvailableFacts);
            RulesList = _parser.ParseRules(AllAvailableFacts);
        }

        private static bool CheckNegative(Token token, bool? value)
        {
            return token.IsNegative ? !(bool) value : (bool) value;
        }

        private static bool AndInExpression(
            IReadOnlyCollection<Token> conclusion)
        {
            foreach (var token in conclusion)
            {
                if (token.Type != TokenType.Fact &&
                    token.Type != TokenType.And)
                    return false;
            }

            foreach (var token in conclusion)
            {
                if (token.Type == TokenType.Fact &&
                    (token.Value.Value == false && token.IsNegative == false ||
                     token.IsNegative && token.Value.Value == true))
                    return false;
            }

            return true;
        }

        private bool BackwardChaining(string search)
        {
            var multipleConclusions = new List<bool>();
            foreach (var rule in RulesList)
            {
                if (rule.Conclusion.Count == 1 &&
                    rule.Conclusion[0].Name == search &&
                    rule.Visited == false)
                {
                    rule.Visited = true;
                    multipleConclusions.Add(
                        CheckNegative(rule.Conclusion[0],
                            SolveExpression(rule)));
                }
            }

            if (multipleConclusions.Count > 0)
                return multipleConclusions.Any(c => c);

            foreach (var rule in RulesList)
            {
                if (rule.Visited == false &&
                    rule.Condition.Any(t => t.Name == search) &&
                    AndInExpression(rule.Condition) &&
                    rule.Operation.Type == TokenType.IfAndOnlyIf &&
                    rule.Conclusion.Count == 1 &&
                    rule.Conclusion[0].Value.Value == true)
                {
                    rule.Visited = true;
                    rule.Condition.ForEach(t =>
                    {
                        if (t.Type == TokenType.Fact)
                            t.Value.Value = CheckNegative(t, true);
                    });
                    if (AllAvailableFacts[search].Value != null)
                        return (bool) AllAvailableFacts[search].Value;
                    return true;
                }

                if (rule.Conclusion.Count != 1 &&
                    rule.Visited == false &&
                    AndInExpression(rule.Conclusion) &&
                    rule.Condition.All(t => t.Name != search) &&
                    rule.Conclusion.Any(t => t.Name == search) &&
                    SolveExpression(rule))
                {
                    rule.Visited = true;
                    rule.Conclusion.ForEach(t =>
                    {
                        if (t.Type == TokenType.Fact)
                            t.Value.Value = CheckNegative(t, true);
                    });
                    if (AllAvailableFacts[search].Value != null)
                        return (bool) AllAvailableFacts[search].Value;
                    return true;
                }
            }

            return false;
        }

        private bool SolveExpression(Rule rule)
        {
            var outputStack = new List<Token>();

            rule.Visited = true;
            if (rule.Condition.Count == 1)
            {
                var fact = rule.Condition[0];
                if (fact.Value.Value == null)
                    fact.Value.Value = BackwardChaining(rule.Condition[0].Name);
                return CheckNegative(fact, fact.Value.Value);
            }

            rule.Condition.ForEach(t =>
            {
                if (ExpressionEvaluator.IsOperatorType(t))
                {
                    var f1 = outputStack.Pop();
                    var f2 = outputStack.Pop();
                    if (f1.Value.Value == null)
                    {
                        f1.Value.Value = BackwardChaining(f1.Name);
                    }

                    if (f2.Value.Value == null)
                    {
                        f2.Value.Value = BackwardChaining(f2.Name);
                    }

                    outputStack.Add(new Token(
                        ExpressionEvaluator.PerformOperation(
                            CheckNegative(f1, f1.Value.Value),
                            CheckNegative(f2, f2.Value.Value),
                            t.Type)));
                }
                else
                {
                    outputStack.Add(t);
                }
            });
            if (outputStack.Count > 1)
            {
                throw new InvalidDataException("The expression is not correct");
            }

            rule.Visited = false;
            return (bool) outputStack.Pop().Value.Value;
        }

        public void Solve()
        {
            foreach (var fact in _queryFactsList)
            {
                if (AllAvailableFacts[fact].Value == null)
                {
                    AllAvailableFacts[fact].Value = BackwardChaining(fact);
                }
            }

            foreach (var fact in _queryFactsList)
            {
                Console.WriteLine(fact + "  is  " +
                                  AllAvailableFacts[fact].Value);
            }
        }
    }
}

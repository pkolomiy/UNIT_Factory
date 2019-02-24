using System;
using System.Collections.Generic;
using System.Linq;
using ExpertSystem.Models;
using MoreLinq.Extensions;

namespace ExpertSystem
{
    public class Parser
    {
        private readonly List<List<Token>> _tokenList;
        private readonly ExpressionEvaluator _expressionEvaluator;

        public Parser(List<List<Token>> tokenList)
        {
            _tokenList = tokenList;
            _expressionEvaluator = new ExpressionEvaluator();
        }

        public Dictionary<string, Fact> GetAllFacts()
        {
            var res = _tokenList.SelectMany(x => x.Where(y =>
                    y.Type == TokenType.Fact)).DistinctBy(x => x.Name)
                .ToDictionary(x => x.Name, x => new Fact());

            return res;
        }

        public List<string> GetQueryFacts(Dictionary<string, Fact> allFacts)
        {
            var queries = _tokenList.SelectMany(x => x.Where(z => z.Type == TokenType.Query)).ToList().First();
            var query = new List<string>();
            queries.Name.ToCharArray().ForEach(x =>
            {
                var key = x.ToString();
                if (key == "?") return;
                if (!allFacts.ContainsKey(key))
                    allFacts.Add(key, new Fact());
                query.Add(key);
            });

            return query;
        }

        public void InitiateFacts(Dictionary<string, Fact> allFacts)
        {
            var initial = _tokenList.SelectMany(x => x.Where(z => z.Type == TokenType.InitialFact)).ToList().First();
            initial.Name.ToCharArray().ForEach(x =>
            {
                var key = x.ToString();
                if (key == "=") return;
                if (!allFacts.ContainsKey(key))
                    allFacts.Add(key, new Fact());
                allFacts[key].Value = true;
            });
        }

        public List<Rule> ParseRules(Dictionary<string, Fact> allFacts)
        {
            var ruleList = new List<Rule>();
            foreach (var rule in _tokenList)
            {
                var ruleObj = new Rule();
                var tokens = rule.Where(t => t.Type != TokenType.Comment
                                             && t.Type != TokenType
                                                 .SequenceTerminator
                                             && t.Type != TokenType.InitialFact
                                             && t.Type != TokenType.Query)
                    .ToList();
                if (tokens.Count == 0)
                    continue;

                var i = 0;
                while (i < tokens.Count &&
                       tokens[i].Type != TokenType.IfAndOnlyIf &&
                       tokens[i].Type != TokenType.Implies)
                {
                    ruleObj.Condition.Add(tokens[i].Type == TokenType.Fact
                        ? new Token(tokens[i].Name, allFacts[tokens[i].Name])
                        : new Token(tokens[i].Type, tokens[i].Name));
                    i++;
                }

                if (i < tokens.Count &&
                    (tokens[i].Type == TokenType.IfAndOnlyIf ||
                     tokens[i].Type == TokenType.Implies))
                {
                    ruleObj.Operation = tokens[i];
                    i++;
                }

                while (i < tokens.Count)
                {
                    ruleObj.Conclusion.Add(tokens[i].Type == TokenType.Fact
                        ? new Token(tokens[i].Name, allFacts[tokens[i].Name])
                        : new Token(tokens[i].Type, tokens[i].Name));
                    i++;
                }
                Validator.ValidateRule(ruleObj);

                ruleObj.Condition =
                     _expressionEvaluator.Evaluate(ruleObj.Condition);

                ruleObj.Conclusion =
                    _expressionEvaluator.Evaluate(ruleObj.Conclusion);

                ruleList.Add(ruleObj);
            }

            if (ruleList.Count == 0)
                throw new Exception("No rules");
            return ruleList;
        }
    }
}

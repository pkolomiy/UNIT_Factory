using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ExpertSystem.Models;
using MoreLinq;

namespace ExpertSystem
{
    public static class Validator
    {
        private static List<TokenType> _expectedInRule = new List<TokenType>
        {
            TokenType.And, TokenType.CloseParenthesis, TokenType.Fact, TokenType.Not,
            TokenType.OpenParenthesis, TokenType.Or, TokenType.Xor
        };

        private static List<TokenType> _expectedInOperation = new List<TokenType>
        {
            TokenType.Or, TokenType.And, TokenType.Xor
        };

        public static void ValidateTokenList(List<List<Token>> tokenList)
        { 

            if (tokenList == null || tokenList.Count == 0)
                throw new Exception("No input data");

            var facts = tokenList.SelectMany(x => x.Where(t => t.Type != TokenType.Comment &&
                                                   t.Type != TokenType.NotDefined &&
                                                   t.Type != TokenType.SequenceTerminator)).ToList();
            if (!facts.Any())
                throw new Exception("Only comments in file");

            var queryIndex = facts.FindIndex(z => z.Type == TokenType.Query);
            var initialFactIndex = facts.FindIndex(z => z.Type == TokenType.InitialFact);

            if (queryIndex != facts.Count-1)
                throw new Exception("File should end with a query");
            if (initialFactIndex != queryIndex - 1)
                throw new Exception("Initial facts declarations should go before query declaration");


            var rules = facts.Where(z => z.Type != TokenType.InitialFact && z.Type != TokenType.Query);
            if (!rules.Any())
                throw new Exception("No rules in file");

            var initial = tokenList.SelectMany(x => x.Where(z => z.Type == TokenType.InitialFact)).ToList();
            if (initial == null || initial.Count != 1)
                throw new Exception("Invalid number of Initial facts");

            var extra = initial.First().Name.ToCharArray().Where(c => c != '=' && char.IsLetter(c) == false).ToList();
            if (extra.Any())
                throw  new Exception("Initial facts contain extra chars");
            var query = tokenList.SelectMany(x => x.Where(z => z.Type == TokenType.Query)).ToList();
            if (query == null || query.Count != 1)
                throw new Exception("Invalid number of Query facts");

            extra = query.First().Name.ToCharArray().Where(t => t != '?' && char.IsLetter(t)== false).ToList();
            if (extra.Any())
                throw new Exception("Query facts contain extra chars");
        }

        public static void ValidateRule(Rule ruleObj)
        {
            if (!ruleObj.Condition.Any()
                || !ruleObj.Conclusion.Any()
                || ruleObj.Operation == null)
            {
                throw new Exception("Invalid rule encountered");
            }

            //condition validation
            ValidateRulePart(ruleObj.Condition);
            //conclusion validation
            ValidateRulePart(ruleObj.Conclusion);
        }

        public static void ValidateRulePart(List<Token> part)
        {
            //extra types in tokens
            var extra = part.Where(z => !_expectedInRule.Contains(z.Type));
            if (extra.Any())
            {
                throw new Exception("Something strange happened, invalid type in conclusion/conditiob");
            }

            //not valid number of parenthesis
            int openP = part.Count(z => z.Type == TokenType.OpenParenthesis);
            int closeP = part.Count(z => z.Type == TokenType.CloseParenthesis);
            if (openP != closeP)
                throw new Exception("Invalid number of parenthesis");

            if (_expectedInOperation.Contains(part.First().Type))
                throw new Exception("Rule can't begin with operator");

            if (_expectedInOperation.Contains(part[part.Count - 1].Type))
                throw new Exception("Rule can't end with operator");

            for (int i = 0; i < part.Count; i++)
            {
                if (part[i].Type == TokenType.Not)
                {
                    i++;
                    if (part[i].Type != TokenType.Fact)
                        throw new Exception("Not operator should be followed by fact");
                }
                if (i + 1 < part.Count && part[i].Type == TokenType.Fact 
                                       && (part[i+1].Type == TokenType.Fact || part[i + 1].Type == TokenType.Not))
                    throw new Exception("Fact can't be followeb by a fact or not operator");
                if (i + 1 < part.Count && _expectedInOperation.Contains(part[i].Type)
                                       && _expectedInOperation.Contains(part[i + 1].Type))
                    throw new Exception("Fact can't be followeb by a fact or not operator");

            }

        }
    }
}

using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Text.RegularExpressions;
using ExpertSystem.Models;

namespace ExpertSystem
{
    public class Lexer
    {
        private List<TokenDefinition> TokenDefinitions { get; }

        public Lexer()
        {
            TokenDefinitions = new List<TokenDefinition>
            {
                new TokenDefinition(TokenType.And, @"^\+"),
                new TokenDefinition(TokenType.OpenParenthesis, @"^\("),
                new TokenDefinition(TokenType.CloseParenthesis, @"^\)"),
                new TokenDefinition(TokenType.Not, @"^!"),
                new TokenDefinition(TokenType.Or, @"^\|"),
                new TokenDefinition(TokenType.Xor, @"^\^"),
                new TokenDefinition(TokenType.Implies, "^=>"),
                new TokenDefinition(TokenType.IfAndOnlyIf, "^<=>"),
                new TokenDefinition(TokenType.Comment, "^#.*\\n*"),
                new TokenDefinition(TokenType.Fact, "^[A-Z]"),
                new TokenDefinition(TokenType.InitialFact, @"^\=[A-Z]*"),
                new TokenDefinition(TokenType.Query, @"^\?[A-Z]+")
            };
        }

        public List<List<Token>> TokenizeFile(string filePath)
        {
            var input = File.ReadAllLines(filePath);
            var tokenList = new List<List<Token>>();
            foreach (var line in input)
            {
                tokenList.Add(TokenizeLine(line));
            }

            Validator.ValidateTokenList(tokenList);
            return tokenList;
        }

        public List<Token> TokenizeLine(string input)
        {

            var tokens = new List<Token>();

            string remainingText = input;
            while (!string.IsNullOrWhiteSpace(remainingText))
            {
                var match = FindMatch(remainingText);
                if (match.IsMatch)
                {
                    tokens.Add(new Token(match.TokenType, match.Value));
                    remainingText = match.RemainingText;
                }
                else
                {
                    if (IsWhitespace(remainingText))
                    {
                        remainingText = remainingText.Substring(1);
                    }
                    else
                    {
                        var invalidTokenMatch = CreateInvalidTokenMatch(remainingText);
                        throw new Exception(invalidTokenMatch.Value + " is not valid instruction. Program has been terminated.");
                    }
                }
            }


            tokens.Add(new Token(TokenType.SequenceTerminator, string.Empty));

            return tokens;
        }

        private TokenMatch FindMatch(string input)
        {
            foreach (var tokenDefinition in TokenDefinitions)
            {
                var match = tokenDefinition.Match(input);
                if (match.IsMatch)
                    return match;
            }

            return new TokenMatch { IsMatch = false };
        }

        private bool IsWhitespace(string input)
        {
            return Regex.IsMatch(input, "^\\s+");
        }

        private TokenMatch CreateInvalidTokenMatch(string input)
        {
            var match = Regex.Match(input, "(^\\S+\\s)|^\\S+");
            if (match.Success)
            {
                return new TokenMatch()
                {
                    IsMatch = true,
                    RemainingText = input.Substring(match.Length),
                    TokenType = TokenType.NotDefined,
                    Value = match.Value.Trim()
                };
            }

            throw new InvalidExpressionException("Error in input file.");
        }
    }
}

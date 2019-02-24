using System.Text.RegularExpressions;
using ExpertSystem.Models;

namespace ExpertSystem
{
    public class TokenDefinition
    {
        private readonly Regex _regex;
        private readonly TokenType _tokenType;

        public TokenDefinition(TokenType tokenType, string regexPattern)
        {
            _regex = new Regex(regexPattern);
            _tokenType = tokenType;
        }

        public TokenMatch Match(string inputString)
        {
            var match = _regex.Match(inputString);
            if (match.Success)
            {
                string remainingText = string.Empty;
                if (match.Length != inputString.Length)
                    remainingText = inputString.Substring(match.Length);

                return new TokenMatch()
                {
                    IsMatch = true,
                    RemainingText = remainingText,
                    TokenType = _tokenType,
                    Value = match.Value
                };
            }
            return new TokenMatch() { IsMatch = false };

        }
    }
}

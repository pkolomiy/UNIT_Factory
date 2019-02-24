using System.Collections.Generic;
using System.Linq;
using ExpertSystem.Models;

namespace ExpertSystem
{
    public static class TokenExtensions
    {
        public static Token Pop(this List<Token> tokens)
        {
            var lastIndex = tokens.Count - 1;
            var last = tokens[lastIndex];
            tokens.RemoveAt(lastIndex);
            return last;
        }
    }
}

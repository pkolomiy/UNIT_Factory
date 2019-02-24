using System.Collections.Generic;

namespace ExpertSystem.Models
{
    public class Token
    {

        public TokenType Type { get; set; }
        public string Name { get; set; }
        public Fact Value { get; set; }
        public bool IsNegative { get; set; }

        public Token(string name, Fact value)
        {
            Type = TokenType.Fact;
            Name = name;
            Value = value;
        }

        public Token(TokenType type, string name)
        {
            Type = type;
            Name = name;
        }

        public Token(bool value)
        {
            Type = TokenType.Fact;
            Value = new Fact(value);
        }
    }
}

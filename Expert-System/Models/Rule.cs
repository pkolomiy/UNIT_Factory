using System;
using System.Collections.Generic;
using System.Text;

namespace ExpertSystem.Models
{
    public class Rule
    {
        public List<Token> Condition { get; set; }
        public List<Token> Conclusion { get; set; }
        public Token Operation { get; set; }
        public bool Visited { get; set; }

        public Rule()
        {
            Conclusion = new List<Token>();
            Condition = new List<Token>();
            Visited = false;
        }
    }
}

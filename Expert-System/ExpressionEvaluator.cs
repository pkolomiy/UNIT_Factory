using System;
using System.Collections.Generic;
using System.IO;
using ExpertSystem.Models;

namespace ExpertSystem
{
    public class ExpressionEvaluator
    {
        private static readonly List<TokenType> Operators = new List<TokenType>
        {
            TokenType.OpenParenthesis,
            TokenType.CloseParenthesis,
            TokenType.Not,
            TokenType.And,
            TokenType.Or,
            TokenType.Xor
        };


        public static bool IsOperatorType(Token fact)
        {
            return Operators.Contains(fact.Type);
        }

        public static bool PerformOperation(bool fact1, bool fact2, TokenType operation)
        {
            if (operation == TokenType.And)
                return fact1 && fact2;
            if (operation == TokenType.Or)
                return fact1 || fact2;
            if (operation == TokenType.Xor)
                return fact1 ^ fact2;
            throw new Exception("Attempt to perform invalid operation");
        }

        public List<Token> Evaluate(List<Token> expression)
        {
            var operands = new List<Token>();
            var stack = new List<Token>();
            var opened = false;

            for (int i = 0; i < expression.Count; i++)
            {
                if (IsOperatorType(expression[i]))
                {
                    if (expression[i].Type == TokenType.CloseParenthesis)
                    {
                        opened = false;
                        var op = operands.Pop();
                        while (op.Type != TokenType.OpenParenthesis)
                        {
                            stack.Add(op);
                            op = operands.Pop();
                        }
                    }
                    else
                    {
                        if (expression[i].Type != TokenType.OpenParenthesis)
                        {
                            if (expression[i].Type == TokenType.Not)
                            {
                                i++;
                                if (expression[i].Type != TokenType.Fact)
                                {
                                    throw new InvalidDataException("No fact after not operand");
                                }
                                expression[i].IsNegative = true;
                                stack.Add(expression[i]);
                                continue;
                            }
                            if (operands.Count != 0)
                            {
                                var lastOperand = operands[operands.Count - 1];

                                while (operands.Count - 1 > 0 && expression[i].Type <= lastOperand.Type)
                                {
                                    stack.Add(operands.Pop());
                                    lastOperand = operands[operands.Count - 1];
                                }
                            }
                        }
                        else
                        {
                            opened = true;
                        }
                        operands.Add(expression[i]);
                    }
                }
                else
                {
                    if (expression[i].Type == TokenType.Fact)
                    {
                        stack.Add(expression[i]);
                    }

                }
            }

            if (opened)
            {
                throw new InvalidDataException("The expression is not correct");
            }

            while (operands.Count > 0)
                stack.Add(operands.Pop());

            return stack;
        }
    }
}

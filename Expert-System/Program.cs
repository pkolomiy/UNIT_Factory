using System;
using System.IO;

namespace ExpertSystem
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                if (args.Length != 1)
                {
                    throw new Exception("Pass file as an argument");
                }
                var inputFileName = args[0];
                if (!File.Exists(inputFileName))
                {
                    throw new FileNotFoundException();
                }

                var tokens = new Lexer().TokenizeFile(inputFileName);
                var parser = new Parser(tokens);
                var solver = new Solver(parser);
                solver.Init();
                solver.Solve();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}

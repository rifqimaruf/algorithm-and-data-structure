using System;
using System.Text.RegularExpressions;

public class Kata
{
    public static bool Validate_hello(string greetings)
    {
        if (greetings == null) return false;

        // Convert the input string to lowercase to make it case-insensitive
        greetings = greetings.ToLower();

        // List of valid greetings in different languages
        string[] hello = { "hello", "ciao", "salut", "hallo", "hola", "ahoj", "czesc" };

        // Remove all non-alphabet characters and split the string by whitespace
        string[] words = Regex.Split(greetings, @"[^a-zA-Z]+");

        // Check if any of the words in the cleaned string match a valid greeting
        foreach (string word in words)
        {
            foreach (string validGreeting in hello)
            {
                if (word == validGreeting)
                {
                    return true;
                }
            }
        }

        return false;
    }
}

public class Program
{
    public static void Main()
    {
        string input = Console.ReadLine();
        bool result = Kata.Validate_hello(input);
        Console.WriteLine(result);
    }
}

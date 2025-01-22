using System;
using NUnit.Framework;

[TestFixture]
public class Tests
{
    [Test]
    public static void FixedTest()
    {
        Assert.That(Kata.EvalObject(1, 1, '+'), Is.EqualTo(2));
        Assert.That(Kata.EvalObject(1, 1, '-'), Is.EqualTo(0));
        Assert.That(Kata.EvalObject(1, 1, '/'), Is.EqualTo(1));
        Assert.That(Kata.EvalObject(1, 1, '*'), Is.EqualTo(1));
        Assert.That(Kata.EvalObject(1, 1, '%'), Is.EqualTo(0));
        Assert.That(Kata.EvalObject(1, 1, '^'), Is.EqualTo(1));
    }
}

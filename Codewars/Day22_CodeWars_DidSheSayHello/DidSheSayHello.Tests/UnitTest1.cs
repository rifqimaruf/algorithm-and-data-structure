using System;
using System.Collections.Generic;
using System.Linq;
using NUnit.Framework;

[TestFixture]
public class Test
{
    [Test]
    public void Test1()
    {
        Assert.That(Kata.Validate_hello("hello"), Is.True);
        Assert.That(Kata.Validate_hello("ciao bella!"), Is.True);
        Assert.That(Kata.Validate_hello("salut"), Is.True);
        Assert.That(Kata.Validate_hello("hallo, salut"), Is.True);
        Assert.That(Kata.Validate_hello("hombre! Hola!"), Is.True);
        Assert.That(Kata.Validate_hello("Hallo, wie geht's dir?"), Is.True);
        Assert.That(Kata.Validate_hello("AHOJ!"), Is.True);
        Assert.That(Kata.Validate_hello("czesc"), Is.True);
        Assert.That(Kata.Validate_hello("Ahoj"), Is.True);
        Assert.That(Kata.Validate_hello("meh"), Is.False);
    }
}

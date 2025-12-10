function divisors(integer)
{
    // divisor
    const result = [];
    for (let i = 2; i < integer; i++) {
        if (integer % i === 0) {
            result.push(i);
        }
    }
    if (result.length > 0) return result;

    // cek for prime number
    if (integer <= 1) return [];
    for (let i = 2; i <= Math.sqrt(integer); i++) {
        if (integer % i === 0) return [];
    }
    return integer + " is prime";
    
}

// examples
console.log(divisors(2)); // [3,5]
console.log(divisors(3)); // [3,5]
console.log(divisors(15)); // [3,5]
console.log(divisors(12)); // [2,3,4,6]
console.log(divisors(13)); // "13 is a prime"
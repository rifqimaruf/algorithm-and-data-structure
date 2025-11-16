function pigIt(str)
{
    str = str.split(' ');
    for (let i = 0;i < str.length;i++)
    {
        if (/^[a-zA-Z]+$/.test(str[i])) {
            str[i] = str[i].substring(1) + str[i][0] + 'ay';
        }
        // /^[a-zA-Z]+$/ -> checks if the word contains only letters
        // str[i][0] -> first character on i word
        // str[i].substring(1) -> from second character to end of i word
    }
    return str.join(' ');
}

// examples
console.log(pigIt('Pig latin is cool'));
console.log(pigIt('Hello world !')); // ! skiped
console.log(pigIt('111 !# %asd22'));// all skiped
console.log(pigIt('Hai! Hello. Why, !there?')); // all skiped because of punctuation
function dnaStrand(dna)
{
    let complement = {
        'A': 'T',
        'T': 'A',
        'C': 'G',
        'G': 'C'
    }
    return dna.split('').map(nucleotide => complement[nucleotide]).join('');
}

// examples
console.log(dnaStrand("AAAA")); 
console.log(dnaStrand("ATTGC"));
console.log(dnaStrand("GTAT"));
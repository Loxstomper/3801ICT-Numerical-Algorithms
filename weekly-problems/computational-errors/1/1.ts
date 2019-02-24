function factorial(n: number): number {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

function calculate(power: number, terms: number): number {
    let val: number = 1;

    for (let i: number = 1; i < terms; i ++) {
        val += Math.pow(power, i) / factorial(i);
    }

    return val;
}


let power: number = 0.5;
let previous_digits: string;
let current: number = 0;
let current_digits: string = '';
let sigDigits: number = 10;

for (let i: number = 1; i < 100; i ++) {
    current = calculate(power, i);

    // gross
    if (i > 1) {
        current_digits = current.toString().split('.')[1].slice(0, sigDigits);
    }

    if (current_digits == previous_digits) {
        break;
    }

    previous_digits = current_digits;

    console.log(i, Number('1.' + current_digits));
}



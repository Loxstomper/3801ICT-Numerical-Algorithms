function factorial(n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
function calculate(power, terms) {
    var val = 1;
    for (var i = 1; i < terms; i++) {
        val += Math.pow(power, i) / factorial(i);
    }
    return val;
}
var power = 0.5;
var previous_digits;
var current = 0;
var current_digits = '';
var sigDigits = 10;
for (var i = 1; i < 100; i++) {
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

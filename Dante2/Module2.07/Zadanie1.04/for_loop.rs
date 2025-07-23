pub fn print_value(value: f64) {
    println!("Value: {}", value);
}

pub fn print_accumulated(value: f64) {
    let mut counter: f64 = 0.0;
    counter = counter + value;
    println!("Value after accumulating: {}", counter);
}

pub fn print_square(value: f64) {
    println!("Value after square: {}", f64::powi(value, 2));
}

pub fn print_abs(value: f64) {
    if value >= 0.0 {
        println!("Value after abs: {}", value);
    }
    else {
        println!("Value after abs: {}", value);
    }
}

pub fn for_loop(start: f64, step: f64, stop: f64, f: fn(f64)) {
    let check: f64 = start;
    if !(step > 0.0 && check <= stop) && !(step < 0.0 && check >= stop) {
        return;
    }
    f(check);
    for_loop(check + step, step, stop, f);
}

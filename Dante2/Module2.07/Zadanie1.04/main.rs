use crate::for_loop::{for_loop, print_abs, print_accumulated, print_square, print_value};

mod for_loop;

fn main() {
    let types: &[fn(f64)] = &[print_abs, print_accumulated, print_square, print_value];

    let mut input: String = String::new();

    println!("Enter start: ");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let start: f64 = input.trim().parse().expect("Incorrect parse");

    println!("Enter step: ");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let step: f64 = input.trim().parse().expect("Incorrect parse");

    println!("Enter end: ");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let end: f64 = input.trim().parse().expect("Incorrect parse");

    if step > 0.0 && start > end || step == 0.0 {
        panic!("Incorrect input data");
    }
    if start < end && step < 0.0 {
        panic!("Incorrect input data");
    }

    println!("Enter type: ");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let pick: usize = input.trim().parse().expect("Incorrect parse");

    if pick > 3 {
        panic!("Incorrect input");
    }

    for_loop(start, step, end, types[pick]);
}

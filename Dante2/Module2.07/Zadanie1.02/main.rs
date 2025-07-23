use crate::int_operations::{get_function};
mod int_operations;

fn main() {
    let mut input: String = String::new();

    input.clear();
    println!("Enter a: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let a: i32 = input.trim().parse().expect("Incorrect parse");

    input.clear();
    println!("Enter b: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let b: i32 = input.trim().parse().expect("Incorrect parse");

    input.clear();
    println!("Enter type: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let t: i32 = input.trim().parse().expect("Incorrect parse");

    println!("Result is: {}", get_function(t)(a, b));
}

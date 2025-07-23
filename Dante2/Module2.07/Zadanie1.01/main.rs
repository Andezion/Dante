use crate::int_operations::{add_int, calculate, div_int, mul_int, sub_int};

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

    match t {
        0 => {
            print!("Add: {}", calculate(a, b, add_int));
        },
        1 => {
            print!("Sub: {}", calculate(a, b, sub_int));
        },
        2 => {
            print!("Mul: {}", calculate(a, b, mul_int));
        },
        3 => {
            print!("Div: {}", calculate(a, b, div_int));
        },
        _other => {
            panic!("Incorrect input!");
        }
    }
}

fn add(a: f32, b: f32) -> f32 {
    a + b
}

fn subtract(a: f32, b: f32) -> f32 {
    a - b
}

fn multiply(a: f32, b: f32) -> f32 {
    a * b
}

fn divide(a: f32, b: f32) -> f32 {
    if b == 0.0 {
        return -1.0;
    }
    a / b
}

fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let a: f32 = input.trim().parse().expect("Error");

    input.clear();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let b: f32 = input.trim().parse().expect("Error");

    println!("Add: {}", add(a, b));
    println!("Subtract: {}", subtract(a, b));
    println!("Multiply: {}", multiply(a, b));

    let result: f32 = divide(a, b);
    if result == -1.0 {
        panic!("Operation not permitted");
    }
    else {
        println!("Divide: {}", result);
    }
}

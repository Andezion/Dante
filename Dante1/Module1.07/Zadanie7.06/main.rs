fn add(a: f32, b: f32) -> f32 {
    a + b
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

    println!("{}", add(a, b));
}

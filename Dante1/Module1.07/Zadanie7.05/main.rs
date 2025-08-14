fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let a: i32 = input.trim().parse().expect("Error");

    input.clear();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let b: i32 = input.trim().parse().expect("Error");

    println!("{}", add(a, b));
}

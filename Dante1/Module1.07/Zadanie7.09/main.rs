fn poly(number: f32) -> f32 {
    5.0 * number * number + 12.55 * number + number + 0.75
}

fn main() {
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("err");
    let number: f32 = input.trim().parse().expect("err");

    println!("Result is: {:.2}", poly(number));
}

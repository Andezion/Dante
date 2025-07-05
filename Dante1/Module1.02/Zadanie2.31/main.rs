fn main() {
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let number: i32 = input.trim().parse().expect("Incorrect parse");

    match number {
        1_i32..=5_i32 => print!("Dzien roboczy"),
        6..7 => print!("Weekend"),
        _other => panic!("Incorrect input"),
    }
}

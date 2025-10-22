fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");

    println!("Enter: ");
    let storage: Vec<String> = input.trim()
        .split_whitespace()
        .map(String::from)
        .collect();

    println!("Day: {} Month: {} Year: {}", storage[0], storage[1], storage[2]);
}

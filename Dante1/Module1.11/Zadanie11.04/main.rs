fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");

    let storage: Vec<String> = input.trim()
        .split_whitespace()
        .map(String::from)
        .collect();

    for i in 0..storage.len() {
        println!("{} ", storage[i]);
    }
}

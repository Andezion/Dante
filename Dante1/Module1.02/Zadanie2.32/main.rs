use regex::Regex;

fn main() {
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let result: &str = input.trim();

    let re = Regex::new(r"^\s*([+-]?\d+)\s+([+-]?\d+)\s*$").expect("Invalid regex");

    let mut number_one: i32 = 0;
    let mut number_two: i32 = 0;
    if let Some(caps) = re.captures(&result) {
        number_one = caps[1].parse().expect("Incorrect number 1");
        number_two = caps[2].parse().expect("Incorrect number 2");
    }

    input.clear();
    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let letter: char = input.trim().parse().expect("Incorrect");

    match letter {
        '+' => print!("{} + {} = {}", number_one, number_two, number_one + number_two),
        '-' => print!("{} - {} = {}", number_one, number_two, number_one - number_two),
        '*' => print!("{} * {} = {}", number_one, number_two, number_one * number_two),
        '/' => print!("{} / {} = {}", number_one, number_two, number_one as f32 / number_two as f32),
        _other => panic!("Error!")
    }
}

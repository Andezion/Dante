fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");
    let data = input.as_str();

    println!("Enter: ");

    for i in 0..data.len() - 1 {
        if data.chars().nth(i) == Option::from('-') || data.chars().nth(i) == Option::from('+') {
            if data.chars().nth(i + 1) == Option::from('-') || data.chars().nth(i + 1) == Option::from('+') {
                panic!("Incorrect");
            }
        }
        if data.chars().nth(i).expect("Error").is_ascii_alphanumeric() {
            panic!("Incorrect");
        }
    }

    let mut counter: u64 = 0;
    let mut number: u64 = 0;
    let mut temp: char = '+';

    for i in 0..data.len() {
        if data.chars().nth(i).expect("Error").is_ascii_alphanumeric() {
            number = number * 10 + (data.chars().nth(i).expect("Error") as u8 - '0' as u8) as u64;
        }
        else if data.chars().nth(i) == Option::from('-') || data.chars().nth(i) == Option::from('+') {
            if temp == '+' {
                counter = counter + number;
            }
            else if temp == '-' {
                counter = counter - number;
            }

            number = 0;
            temp = data.chars().nth(i).expect("Error");
        }
    }

    if temp == '+' {
        counter = counter + number;
    }
    else if temp == '-' {
        counter = counter - number;
    }

    println!("{} ", counter);
}

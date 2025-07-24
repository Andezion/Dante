fn main() {
    let mut input: String = String::new();

    println!("Enter: ");

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect");
    let number: i32 = input.trim().parse().expect("Incorrect");

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect");
    let letter: char = input.trim().parse().expect("Incorrect");

    if letter >= 'a' && letter <= 'h' && number >= 1 && number <= 8 {
        if (letter == 'a' || letter == 'c' || letter == 'e' || letter == 'g') && (number % 2 == 0) ||
            (letter == 'b' || letter == 'd' || letter == 'f' || letter == 'h') && (number % 2 == 1) {
            print!("White");
        }
        if (letter == 'a' || letter == 'c' || letter == 'e' || letter == 'g') && (number % 2 != 0) ||
            (letter == 'b' || letter == 'd' || letter == 'f' || letter == 'h') && (number % 2 == 0)  {
            print!("Black");
        }
    }
    else {
        panic!("Incorrect");
    }
}

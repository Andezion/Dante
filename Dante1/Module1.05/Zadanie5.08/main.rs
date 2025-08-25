fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let input_text = &input;

    let size_of_input_text: usize = input_text.len();
    if size_of_input_text >= 99 {
        panic!("Input is too long");
    }

    let mut reserved_text: Vec<char> = vec![];
    for i in 0..size_of_input_text {
        reserved_text.push(input_text.chars().nth(size_of_input_text - i - 1).expect("popa"));
    }

    if reserved_text[0].is_digit(10) {
        panic!("Incorrect input");
    }

    for i in 0..size_of_input_text - 1 {
        if reserved_text[i].is_digit(10) && reserved_text[i + 1].is_digit(10) {
            panic!("Incorrect input");
        }
    }

    let mut final_text: Vec<char> = vec![];
    let mut j: usize = 0;
    for i in 0..size_of_input_text {
        let mut number: u8 = 1;
        if !reserved_text[i].is_digit(10) {
            final_text.push(reserved_text[i]);
            j += 1;
        }
        else {
            while number != reserved_text[i] as u8 {
                final_text.push(reserved_text[i - 1]);
                number += 1;
                j += 1;
            }
        }
    }

    if j > 200 {
        panic!("Output is too long");
    }

    println!("{:?}", final_text);
}

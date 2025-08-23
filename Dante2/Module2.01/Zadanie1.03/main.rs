use std::fs::File;
use std::io::{BufRead, Error, Read, Write};

fn main() -> Result<(), Error> {
    println!("Enter: ");
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");

    let mut file = match File::open(input.trim()) {
        Ok(f) => f,
        Err(_e) => {
            panic!("err");
        }
    };

    let mut inside: String = String::new();
    file.read_to_string(&mut inside).expect("TODO: panic message");

    input.clear();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");

    let mut output = File::create(&input)?;
    write!(output, "{}", inside)?;

    Ok(())
}

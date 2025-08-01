use std::fs::File;
use std::io::Read;

fn main() -> Result<(), std::io::Error> {
    println!("Enter file name: ");

    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("err");

    let mut file = match File::open(input.trim()) {
        Ok(f) => f,
        Err(_e) => {
            panic!("err");
        }
    };

    input.clear();
    file.read_to_string(&mut input).expect("TODO: panic message");
    println!("{}", input);

    Ok(())
}

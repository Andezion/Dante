use std::fs::File;

fn main() -> Result<(), std::io::Error> {
    println!("Enter file name: ");

    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");

    let file = match File::open(input.trim()) {
        Ok(f) => f,
        Err(_e) => {
            panic!("err");
        }
    };

    let size1 = file.metadata()?.len();

    println!("Size is: {}\n", size1);

    Ok(())
}

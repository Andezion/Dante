fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");

    if input.len() > 50 {
        panic!("Too long!");
    }

    let mut max_number: u32 = 0;
    let mut value: u32 = 0;

    let mut helper: u32 = 0;

    for i in input.chars() {
        if i == '(' {
            helper += 1;

            if helper > max_number {
                max_number = helper;
                value = 1;
            }
            if helper == max_number {
                value += 1;
            }
        }
        if i == ')' {
            helper -= 1;
        }
    }

    println!();
    println!("{} ", max_number);

    for i in 0..input.len() {
        if input.chars().nth(i) == Option::from('(') {
            value += 1;
            if helper == max_number {
                print!("{} ", i)
            }
        }
        if input.chars().nth(i) == Option::from(')') {
            value -= 1;
        }
    }
}

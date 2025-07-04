fn sign(value: i32) -> i32
{
    return (value > 0) as i32 - (value < 0) as i32;
}

fn main()
{
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let number: i32 = input.trim().parse().expect("Incorrect parsing");

    let to_switch: i32 = sign(number);
    if to_switch == 0
    {
        print!("Zero");
    }
    else if to_switch == 1
    {
        print!("Positive");
    }
    else
    {
        print!("Negative");
    }
}

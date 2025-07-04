fn circumference(number: f32) -> f32
{
    if number <= 0.0
    {
        return -1.0
    }
    number * std::f32::consts::PI
}

fn main()
{
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let number: f32 = input.trim().parse().expect("Incorrect number");

    println!("Result is: {}", circumference(number));
}

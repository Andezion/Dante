fn main()
{
    println!("Enter your number one: ");
    
    let mut number_one = String::new();
    std::io::stdin().read_line(&mut number_one).expect("Failed to read line");
    
    println!("Enter your number two: ");
    
    let mut number_two = String::new();
    std::io::stdin().read_line(&mut number_two).expect("Failed to read line");
    
    let number_one: i32 = number_one.trim().parse().expect("Invalid number");
    let number_two: i32 = number_two.trim().parse().expect("Invalid number");
    
    println!("{number_one} + {number_two} = {}", number_one + number_two);
    println!("{number_one} - {number_two} = {}", number_one - number_two);
    println!("{number_one} * {number_two} = {}", number_one * number_two);
    println!("{number_one} / {number_two} = {:.4}", number_one as f32 / number_two as f32);
    
    return;
}

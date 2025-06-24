fn main()
{
    println!("Enter numbers: ");
    
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    
    let chars: Vec<char> = input.trim().chars().collect();
    
    println!("{}{}{}\n{}{}{}\n{}{}{}", 
             chars[0], chars[1], chars[2], 
             chars[3], chars[4], chars[5], 
             chars[6], chars[7], chars[8],);
    
    return;
}

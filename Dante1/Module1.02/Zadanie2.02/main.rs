fn main()
{ 
    println!("Enter: ");

    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let input = input.trim();
    
    let chars: Vec<char> = input.chars().collect();
    
    let res_one: String = chars[1..3].iter().collect();
    let res_two: String = chars[5..].iter().collect();
    
    println!("One: {}", res_one);
    println!("Two: {}", res_two);
}

fn main()
{
    let mut result: f32 = 0.0;
    
    let mut pointer: i32 = 0;

    let mut input: String = String::new();
    
    loop 
    {
        println!("Enter: ");
        
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        let number: f32 = input.trim().parse().expect("Error");
        
        if pointer != 0
        {
            result = result * number;
            print!("{:.2}", result);
        }
        else
        {
            pointer = 1;
            print!("{:.2}", number);
            
            result = number;
        }
    }
    
    return;
}

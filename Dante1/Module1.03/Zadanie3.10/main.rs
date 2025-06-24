fn main()
{
    let mut number_for_while: u32 = 0;
    let mut storage_value: f64 = 0.0;
    
    while number_for_while != 10
    {
        println!("Enter {}: ", number_for_while + 1);
        
        let mut temp_value: String = String::new();
        std::io::stdin().read_line(&mut temp_value).expect("Incorrect input");
        let temp_value: f64 = temp_value.trim().parse().expect("Incorrect parsing");
        
        number_for_while = number_for_while + 1;
        storage_value = storage_value + temp_value;
    }
    
    println!("Sum is: {:.6}", storage_value);
    
    return;
}

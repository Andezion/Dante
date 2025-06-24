fn main()
{
    let mut helper_to_add: u32 = 0;
    
    let mut temp_storage_for_value: f32 = 0.0;
    
    loop 
    {
        println!("Enter: ");
        let mut input: String = String::new();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let input: f32 = input.trim().parse().expect("Incorrect parser");
        
        if input == 0.0
        {
            break;
        }
        
        if helper_to_add != 0
        {
            let difference: f32 = input - temp_storage_for_value;
            println!("{:.6}\n", difference);
        }
        
        temp_storage_for_value = input;
        helper_to_add = 1;
    }
    
    return;
}

fn main()
{
    let mut array:[i32; 11] = [0; 11];
    let mut iterator: usize = 0;
    
    let mut input: String = String::new();
    
    println!("Enter: ");
    
    while iterator != 10
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Failed to input");
        let number: i32 = input.trim().parse().expect("Failed to parse");
        
        if number == -1
        {
            break;
        }

        array[number as usize] += 1;
        
        iterator += 1;
    }
    
    for i in 0 .. 11
    {
        println!("{} - {}", i, array[i as usize]);
    }
    
    return;
}

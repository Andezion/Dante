fn main()
{
    let mut array:[i32; 10] = [0; 10];
    println!("Enter numbers: ");
    
    let mut i: usize = 0;
    while i != 10
    {
        let mut input: String = String::new();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let input: i32 = input.trim().parse().expect("Incorrect number");
        
        array[i] = input;
        i = i + 1;

        let mut input: String = String::new();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let input: i32 = input.trim().parse().expect("Incorrect number");
        
        array[i] = input;
        i = i + 1;
    }
    
    for i in 0..10
    {
        if array[i] % 2 == 0
        {
            println!("{} is even", array[i]);
        }
        else 
        {  
            println!("{} is odd", array[i]);
        }
    }
    
    return;
}

fn main()
{
    let mut array:[i32; 10] = [0; 10];
    println!("Enter numbers: ");

    let mut input: String = String::new();
    let mut i: usize = 0;
    while i != 10
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let num: i32 = input.trim().parse().expect("Incorrect number");
        
        array[i] = num;
        i = i + 1;

        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let num: i32 = input.trim().parse().expect("Incorrect number");
        
        array[i] = num;
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

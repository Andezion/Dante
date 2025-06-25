fn main()
{
    let mut array:[i32; 100] = [0; 100];
    let mut size_of_array: usize = 0;
    
    println!("Enter: ");
    
    let mut input: String = String::new();
    while size_of_array != 100
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect number");
        
        if number == 0
        {
            break;
        }
        
        array[size_of_array] = number;
        size_of_array += 1;
    }
    
    if size_of_array < 1
    {
        panic!("Nothing to show");
    }
    
    let mut i: i32 = (size_of_array - 1) as i32;
    while i >= 0
    {
        let temp: usize = i as usize;
        if i % 2 == 0
        {
            print!("{} ", array[temp]);
        }
        i -= 1;
    }
    
    return;
}

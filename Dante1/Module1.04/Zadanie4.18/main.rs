fn main()
{
    let mut array:[i32; 200] = [0; 200];
    let mut size_of_array: usize = 0;
    
    println!("Enter your array: ");
    
    let mut input: String = String::new();
    
    loop
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect number");
        
        array[size_of_array] = number;
        
        if size_of_array == 100 || array[size_of_array] == 0
        {
            break;
        }
        
        size_of_array = size_of_array + 1;
    }
    
    if size_of_array < 1
    {
        panic!("Not enough data available");
    }
    
    for i in 0..size_of_array
    {
        let mut temp: u8 = 0;
        for j in 0..i
        {
            if array[i] == array[j]
            {
                temp = 1;
                break;
            }
        }
        if temp == 0
        {
            print!("{} ", array[i]);
        }
    }
    
    return;
}

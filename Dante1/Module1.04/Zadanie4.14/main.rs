fn is_non_monotonic(a: i32, b: i32, c: i32) -> bool
{
    return (a < b && b > c) || (a > b && b < c);
}

fn main()
{
    let mut array:[i32; 4000] = [0; 4000];
    let mut size_of_array: usize = 0;
    
    println!("Enter: ");
    
    let mut input: String = String::new();
    for _i in 0 .. 4000
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        let number: i32 = input.trim().parse().expect("Error");
        
        if number == 0
        {
            break;
        }
        
        array[size_of_array] = number;
        size_of_array += 1;
    }
    
    if size_of_array > 1000
    {
        size_of_array = 1000;
    }
    
    if size_of_array < 3
    {
        println!("{}\n{}", 0, 0);
    }
    
    let mut max_length: i32 = 0;
    let mut counter_for_biggest_subarray: i32 = 0;
    
    let mut helper_array:[i32; 1000] = [0; 1000];
    
    for mut i in 0 .. size_of_array - 2
    {
        let mut helper: i32 = 2;
        
        while i as i32 + helper < size_of_array as i32 && 
            is_non_monotonic(array[i + helper as usize - 2], array[i + helper as usize - 1], array[i + helper as usize])
        {
            helper += 1;
        }
        
        if helper > max_length
        {
            max_length = helper;
            counter_for_biggest_subarray = 1;
            helper_array[0] = i as i32;
        }
        else if helper == max_length
        {
            helper_array[counter_for_biggest_subarray as usize] = i as i32;
            counter_for_biggest_subarray += 1;
        }
        
        i += helper as usize * 2;
    }
    
    if max_length >= 3
    {
        println!("{}\n{}", max_length, counter_for_biggest_subarray);
        
        for i  in 0 .. counter_for_biggest_subarray
        {
            print!("{} -", helper_array[i as usize]);
            for j in 0 .. max_length
            {
                print!(" {}", array[(helper_array[i as usize] + j) as usize]);
            }
            println!();
        }
    }
    else
    {
        println!("{}\n{}", 0 , 0);
    }
    
    return;
}

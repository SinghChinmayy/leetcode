#!/usr/bin/env python3
"""
Script to automatically generate and update the README.md with solved LeetCode problems.
This script scans the Leetcode_Codes directory and generates a table of solved problems,
categorized by standard LeetCode topics based on folder structure.
"""

import os
import re
from pathlib import Path
from typing import List, Tuple, Dict

# Extensions to consider as solutions
SOLUTION_EXTENSIONS = {'.cpp', '.py', '.java', '.js', '.ts', '.c', '.go', '.rs', '.sql'}

def extract_problem_number(filename: str) -> int:
    """Extract problem number from filename."""
    match = re.match(r'^(\d+)', filename)
    if match:
        return int(match.group(1))
    return float('inf')

def get_problems_by_category() -> Dict[str, List[Tuple[int, str, str]]]:
    """
    Scan Leetcode_Codes directory and return solved problems grouped by category.
    Returns dict of {category: list of (number, problem_name, file_path)}.
    """
    categories = {}
    codes_dir = Path('Leetcode_Codes')
    
    if not codes_dir.exists():
        print(f"Warning: {codes_dir} directory not found")
        return categories
    
    # Iterate through each subdirectory (category)
    for category_dir in codes_dir.iterdir():
        if category_dir.is_dir():
            category_name = category_dir.name
            problems = []
            seen_problems = {}
            
            # Iterate through files in the category directory
            for file_path in category_dir.iterdir():
                if file_path.is_file() and file_path.suffix.lower() in SOLUTION_EXTENSIONS:
                    filename = file_path.name
                    problem_number = extract_problem_number(filename)
                    
                    # Skip if we've already added this problem number for this category
                    if problem_number in seen_problems:
                        continue
                        
                    # Extract problem name (remove number and extension)
                    problem_name = re.sub(r'^\d+\.\s*', '', filename)
                    problem_name = Path(problem_name).stem
                    
                    seen_problems[problem_number] = True
                    problems.append((problem_number, problem_name, str(file_path)))
            
            if problems:
                # Sort by problem number
                problems.sort(key=lambda x: x[0])
                categories[category_name] = problems
    
    return categories

def get_difficulty(problem_number: int) -> str:
    """
    Determine difficulty level based on problem number.
    This is a heuristic mapping.
    """
    easy_problems = {7, 9, 70, 104, 121, 136, 283, 485, 509}
    medium_problems = {3, 50, 176, 189, 300}
    hard_problems = set()
    
    if problem_number in easy_problems:
        return "Easy"
    elif problem_number in medium_problems:
        return "Medium"
    elif problem_number in hard_problems:
        return "Hard"
    else:
        return "Unknown"

def generate_categorized_index(categories: Dict[str, List[Tuple[int, str, str]]]) -> str:
    """Generate markdown index categorized by topic."""
    if not categories:
        return "No problems solved yet.\n"
    
    markdown = ""
    total_solved = 0
    
    # Sort categories alphabetically
    for category in sorted(categories.keys()):
        problems = categories[category]
        total_solved += len(problems)
        
        markdown += f"### {category}\n\n"
        markdown += "| # | Problem | Difficulty | Solution |\n"
        markdown += "|---|---------|-----------|----------|\n"
        
        for problem_number, problem_name, file_path in problems:
            difficulty = get_difficulty(problem_number)
            ext = Path(file_path).suffix.lower()
            lang_map = {
                '.cpp': 'C++',
                '.py': 'Python',
                '.java': 'Java',
                '.js': 'JavaScript',
                '.ts': 'TypeScript',
                '.c': 'C',
                '.go': 'Go',
                '.rs': 'Rust',
                '.sql': 'SQL'
            }
            lang = lang_map.get(ext, 'Code')
            
            # Create markdown link with proper spacing
            file_link = file_path.replace(' ', '%20')
            solution_link = f"[{lang}](./{file_link})"
            
            markdown += f"| {problem_number} | {problem_name} | {difficulty} | {solution_link} |\n"
        markdown += "\n"
    
    return markdown, total_solved

def update_readme(categories: Dict[str, List[Tuple[int, str, str]]]):
    """Update README.md with the generated categorized problems."""
    readme_path = Path('README.md')
    
    if not readme_path.exists():
        print("Warning: README.md not found")
        return
    
    with open(readme_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Generate new index
    categorized_index, total_solved = generate_categorized_index(categories)
    
    new_problems_section = f"## Solved Problems\n\n{categorized_index}**Total Problems Solved:** {total_solved}\n"
    
    # Pattern to match the solved problems section
    # Matches from ## Solved Problems until the next H2 or end of file
    pattern = r'## Solved Problems\n.*?(?=\n## |$)'
    
    if re.search(pattern, content, re.DOTALL):
        # Replace existing section
        new_content = re.sub(pattern, new_problems_section, content, flags=re.DOTALL)
    else:
        # If section doesn't exist, append it before ## Notes & Resources or at end
        notes_pattern = r'(## Notes & Resources)'
        if re.search(notes_pattern, content):
            new_content = re.sub(notes_pattern, new_problems_section + "\n" + r'\1', content)
        else:
            new_content = content.rstrip() + "\n\n" + new_problems_section
            
    # Also clean up the redundant "Available Solutions" section if it exists
    available_solutions_pattern = r'## Available Solutions\n.*?(?=\n## |$)'
    if re.search(available_solutions_pattern, new_content, re.DOTALL):
        new_content = re.sub(available_solutions_pattern, '', new_content, flags=re.DOTALL)
        # Clean up double newlines
        new_content = re.sub(r'\n{3,}', '\n\n', new_content)

    with open(readme_path, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    print(f"✅ Updated README.md with {total_solved} solved problems across {len(categories)} categories")

def main():
    """Main function."""
    categories = get_problems_by_category()
    update_readme(categories)

if __name__ == '__main__':
    main()

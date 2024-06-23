import requests
import json
import os
import time

arr = [2837,2844,2874,2946,2993,3041,3046,3095,3197]

with open("static/question/all-questions.json", "r") as f:
    questions = json.load(f)
    for item in questions["questions"]:
        id = int(item["frontendQuestionId"])
        if int(item["frontendQuestionId"]) == 3095:
            slug = item["titleSlug"]
            url = f"http://localhost:5000/question/data?slug={slug}"
            res = requests.get(url).json()
            if res["failed"] == False:
                file_path = f'static/question/collection/{slug}.json'
                with open(file_path, 'w') as file:
                    json.dump(res, file, indent=4)
                print("done for #",item["frontendQuestionId"])
            else:
                print("failed for #",item["frontendQuestionId"], res)
                time.sleep(90)
            
            time.sleep(30)


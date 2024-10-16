# This script is used to update the progress of a task in the database.

import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
import os

# 设置字体
font_path = '/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc'
font_prop = fm.FontProperties(fname=font_path)

# font_path = '/System/Library/fonts/PingFang.ttc'
# font_prop = fm.FontProperties(fname=font_path)


# 数据
directory = 'submissions/'
all_items = os.listdir(directory)
members = [item for item in all_items if os.path.isdir(os.path.join(directory, item)) and item != 'README.md']
task_counts = {}
qualified = list()
for member in members:
    folder_path = os.path.join(directory, member)
    items = os.listdir(folder_path)
    if len(items) < 2:
        continue
    else:
        task_counts[member] = len(items)
        qualified.append(member)

for member, count in task_counts.items():
    print(f"{member}: {count}")


# 设置图形大小
plt.figure(figsize=(10, 6))

plt.barh(qualified, task_counts.values(), color='gold', label=f'剩余考核中人数/总人数 {len(qualified)}/{len(member)}\n任务截止日期:\ntask0:9.16\ntask1:9.23\ntask2:期中前\ntask3:11.20\ntask4:11.20\ntask5:11.20\ntask6:11.20' )

# 显示图例
plt.legend(loc="upper right", prop = font_prop)

# 设置标题和标签
plt.title('任务轴', fontproperties = font_prop)
plt.xlabel('任务数量', fontproperties = font_prop)

x_ticks = range(0, 9, 1)
x_labels = [f'task{i-1}' for i in x_ticks]
plt.xticks(x_ticks, x_labels, fontproperties = font_prop)

for label in plt.gca().get_xticklabels() + plt.gca().get_yticklabels():
    label.set_fontproperties(font_prop)

# 存储图表
plt.savefig('assets/task_progress.png')

import numpy as np

def viterbi(init_prob, transition_prob, observation_prob, observed_list):
    num_state = len(init_prob)
    num_steps = len(observed_list)
    maxProbMatrix = np.zeros((num_state, num_steps))
    recordMatrix = [[None for i in range(num_steps)] for j in range(num_state)]

    #1. 动态规划求概率最大值
    for step_i in range(num_steps):
        if step_i == 0:
            for state_j in range(num_state):
                observed_state = observed_list[step_i]
                maxProbMatrix[state_j, step_i] = init_prob[state_j] * observation_prob[state_j, observed_state]
        else:
            for state_j in range(num_state):
                observed_state = observed_list[step_i]
                prev_step_prob_vector = maxProbMatrix[:, step_i - 1]
                maxProbMatrix[state_j, step_i] = np.max(prev_step_prob_vector * transition_prob[:, state_j] * observation_prob[state_j, observed_state])
                recordMatrix[state_j][step_i] = np.argmax(prev_step_prob_vector * transition_prob[:, state_j] * observation_prob[state_j, observed_state])

    #2. 回溯求概率最大值的对应的路径
    max_prob_hidden_list = [np.argmax(maxProbMatrix[:, -1])]
    for step_i in range(num_steps - 2, -1, -1):
        forward_step = step_i + 1
        max_prob_hidden_list.append(recordMatrix[max_prob_hidden_list[-1]][forward_step])

    return max_prob_hidden_list[::-1]

def main():
    # Initial probability
    pai = np.array([0.333333, 0.333333, 0.333333])
    # transition probability
    A = np.array([[0.2, 0.3, 0.5], [0.2, 0.2, 0.6], [0.0, 0.2, 0.8]])
    # Observation probability
    B = np.array([[0.7, 0.2, 0.1], [0.3, 0.4, 0.3], [0.0, 0.1, 0.9]])

    #观测序列
    observedSequence = np.array([0, 2, 1, 0, 2])
    # Status dictionary
    stateDict = {0: "good", 1: "neutral", 2: "bad"}


    max_prob_hidden_list = viterbi(pai, A, B, observedSequence)
    print("Max probability list: ", "->".join(stateDict[state] for state in max_prob_hidden_list))

if __name__ == "__main__":
    main()
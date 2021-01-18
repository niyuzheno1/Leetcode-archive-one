import sys
import argparse

def bd(x , boxes, portsCount, maxBoxes, maxWeight):
    l = x
    r = x
    n = len(boxes)
    cbox = 0
    cweight = 0
    uniques = 0
    u = {}
    while l < n:
        cbox += 1
        cweight += boxes[l][1]
        l = l + 1
        if cbox > maxBoxes or cweight > maxWeight:
            l = l-1
            cbox -= 1
            cweight -= boxes[l][1]
            break
        if boxes[l-1][0] not in u:
            u[boxes[l-1][0]] = 1
            uniques = uniques + 1
    if uniques == 1:
        cnt = 0
        for i in range(r,l-1):
            if(boxes[i][0] != boxes[i+1][0]):
                cnt = cnt + 1
        return l, cnt+2
    while l < n and l > r and boxes[l][0] == boxes[l-1][0] and boxes[l-1][1] + boxes[l][1] < maxWeight:
        l = l-1
        cbox -= 1
        cweight -= boxes[l][1]
    cnt = 0
    for i in range(r,l-1):
        if(boxes[i][0] != boxes[i+1][0]):
            cnt = cnt + 1
    return l, cnt + 2

def boxDelivering(boxes, portsCount, maxBoxes, maxWeight):
    ttrip = 0
    l = 0
    n = len(boxes)
    while l < n:
        u, v= bd(l, boxes, portsCount, maxBoxes, maxWeight)
        ttrip += v;
        l = u
    return ttrip



def main():
    #print(boxDelivering(boxes=[[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]], portsCount = 5, maxBoxes = 5, maxWeight = 7))
    #print(boxDelivering(boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 3, maxWeight = 3))
    #print(boxDelivering(boxes = [[1,2],[3,3],[3,1],[3,1],[2,4]], portsCount = 3, maxBoxes = 3, maxWeight = 6))
    #print(boxDelivering(boxes = [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], portsCount = 3, maxBoxes = 6, maxWeight = 7))
    print(boxDelivering(boxes = [[48,52899],[47,19850],[33,29679],[69,33222],[58,701],[30,76794],[25,81170],[73,23227],[55,20126],[44,36120],[45,31939],[67,19736],[68,38178],[17,83260],[38,15272],[38,78703],[35,17238],[75,18299],[8,20643],[23,49506],[64,11294],[57,52676],[50,72049],[18,62783],[72,47322],[58,17174],[33,91245],[41,20540],[9,52226],[8,56422],[38,67101],[55,84871],[10,22701],[13,65749],[10,75225],[27,13437],[5,82776],[53,69170],[40,19975],[71,52129],[56,92827],[77,91290],[34,52128],[49,42076],[65,14024],[11,20086],[54,72018],[64,64707],[43,53637],[18,81304],[34,769],[33,7418],[60,1473],[44,16057],[45,81799],[50,91388],[2,88844],[50,19037],[50,24485],[2,79102],[3,34503],[49,89167],[18,18198],[30,76362],[61,51312],[53,25332],[53,85378],[43,31053],[74,8190],[55,22288],[56,48727],[66,45387],[12,53165],[46,66319],[48,47049],[34,4879],[20,35950],[27,80365],[59,42479],[50,17398],[63,26273],[27,78622],[57,27062],[16,53519],[42,31522],[39,26623],[35,71692],[33,72780],[23,17746],[2,939],[47,3748],[63,71487],[25,92114],[58,48662],[24,45749],[64,63233],[26,92359],[29,11382],[58,785],[59,11024],[60,55275],[50,66923],[10,6771],[61,31311],[76,61562],[69,22497],[29,24471],[43,90635],[38,40760],[64,87184],[7,19793],[47,47690],[69,9570],[39,16271],[75,87064],[26,26233],[53,69585],[29,68502],[37,16523],[34,10484],[22,88729],[31,80116],[10,17864],[33,47739],[53,67300],[21,68588],[69,58835],[75,79944],[76,13923]], portsCount = 77, maxBoxes = 17, maxWeight = 93070))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()
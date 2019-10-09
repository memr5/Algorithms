package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestKadane(t *testing.T) {
	assert.Equal(t, Kadane([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6)
}
